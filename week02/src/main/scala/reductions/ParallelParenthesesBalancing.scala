package reductions

import common._
import org.scalameter._

import scala.annotation._

object ParallelParenthesesBalancingRunner {

  @volatile var seqResult = false

  @volatile var parResult = false

  val standardConfig = config(
    Key.exec.minWarmupRuns -> 40,
    Key.exec.maxWarmupRuns -> 80,
    Key.exec.benchRuns -> 120,
    Key.verbose -> true
  ) withWarmer (new Warmer.Default)

  def main(args: Array[String]): Unit = {
    val length = 10000
    val chars = new Array[Char](length)
    val threshold = 1000
    val seqtime = standardConfig measure {
      seqResult = ParallelParenthesesBalancing.balance(chars)
    }
    println(s"sequential result = $seqResult")
    println(s"sequential balancing time: $seqtime ms")

    val fjtime = standardConfig measure {
      parResult = ParallelParenthesesBalancing.parBalance(chars, threshold)
    }
    println(s"parallel result = $parResult")
    println(s"parallel balancing time: $fjtime ms")
    println(s"speedup: ${seqtime / fjtime}")
  }
}

object ParallelParenthesesBalancing {

  /** Returns `true` iff the parentheses in the input `chars` are balanced.
    */
  def balance(chars: Array[Char]): Boolean = {
    @tailrec
    def loop(chars: Array[Char], openCount: Int): Int = {
      if (openCount < 0) -1
      else if (chars.isEmpty) openCount
      else if (chars.head == '(') loop(chars.tail, openCount + 1)
      else if (chars.head == ')') loop(chars.tail, openCount - 1)
      else loop(chars.tail, openCount)
    }

    loop(chars, 0) == 0
  }

  /** Returns `true` iff the parentheses in the input `chars` are balanced.
    */
  def parBalance(chars: Array[Char], threshold: Int): Boolean = {

    def traverse(idx: Int, until: Int, arg1: Int, arg2: Int): (Int, Int) = {
      var i = idx

      var openCount = 0
      var unclosedCount = 0

      while (i < until) {
        if (chars(i) == '(')
          openCount += 1
        else if (chars(i) == ')')
          openCount -= 1

        if (openCount < unclosedCount)
          unclosedCount = openCount

        i += 1
      }

      (openCount, unclosedCount)
    }

    def reduce(from: Int, until: Int): (Int, Int) = {
      if (until - from <= threshold) traverse(from, until, 0, 0)
      else {
        val mid = from + (until - from) / 2
        val (left, right) = parallel(
          reduce(from, mid),
          reduce(mid, until)
        )

        val (lOpenCount, lUnclosedCount) = left
        val (rOpenCount, rUnclosedCount) = right

        (lOpenCount + rOpenCount,
          Math.min(lUnclosedCount, lOpenCount + rUnclosedCount))
      }
    }

    reduce(0, chars.length) == (0, 0)
  }

  // For those who want more:
  // Prove that your reduction operator is associative!

}
