package funsets

import scala.annotation.tailrec

object Main extends App {
  import FunSets._
  println(contains(singletonSet(1), 1))
}

object Videos {
  def main(args: Array[String]): Unit = {
    println("Videos")
    println(sum(x => x)(2, 4))
    println(product(x => x)(2, 4))
    println(fact(3))
    println(mapReduce(x => x, (x, y) => x + y, 0)(2, 4))
    println(mapReduce(x => x, (x, y) => x * y, 1)(2, 4))
    println(mapReduceProduct(x => x)(2, 4))
    println(sqrt(2))
  }

  def sum(f: Int => Int)(a: Int, b: Int): Int = {

    @tailrec
    def loop(a: Int, acc: Int): Int = {
      if (a > b) acc
      else loop(a + 1, acc + f(a))
    }

    loop(a, 0)
  }

  def product(f: Int => Int)(a: Int, b: Int): Int = {

    @tailrec
    def loop(a: Int, acc: Int): Int = {
      if (a > b) acc
      else loop(a + 1, acc * f(a))
    }

    loop(a, 1)
  }

  def fact(n: Int): Int = {
    product(x => x)(1, n)
  }

  def mapReduce(map: Int => Int, reduce: (Int, Int) => Int, baseValue: Int)(a: Int, b: Int): Int = {
//    @tailrec
//    def loop(a: Int, acc: Int): Int = {
//      if (a > b) acc
//      else loop(a + 1, reduce(acc, map(a)))
//    }
//
//    loop(a, baseValue)
    if (a > b) baseValue
    else reduce(map(a), mapReduce(map, reduce, baseValue)(a +1, b))
  }

  def mapReduceProduct(f: Int => Int)(a: Int, b: Int): Int = {
    mapReduce(f, (x, y) => x * y, baseValue=1)(a, b)
  }

  val tolerance = 0.0001

  def abs(x: Double): Double = if (x < 0) -x else x

  def isCloseEnough(x: Double, y: Double): Boolean = {
    abs((x - y) / x) / x < tolerance
  }

  def fixedPoint(f: Double => Double)(firstGuess: Double): Double = {
    def iterate(guess: Double): Double = {
      val next = f(guess)
      if (isCloseEnough(guess, next)) next
      else iterate(next)
    }

    iterate(firstGuess)
  }

  def averageDamp(f: Double => Double)(x : Double): Double = (x + f(x)) / 2

  def sqrt(x: Double): Double = {
    fixedPoint(averageDamp(y => x / y))(1.0)
  }
}

object Rationals extends App {
  println(new Rational(1, 2))

  val x = new Rational(1, 2)
  println(x)
  println(-x)

  val y = new Rational(2, 3)
  println(x + y)
  println(x - y)
  println(y + x)
  println(x < y)
  println(x.max(y))
  println(new Rational(2))
}

class Rational(x: Int, y: Int) {
  require(y > 0, "denominator must be positive.")

  def this(x: Int) = this(x, 1)

  private def gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)
  private def abs(x: Int): Int = if (x < 0) -x else x
  // private val g = gcd(x, y)

  //  def numer: Int = x / gcd(x, y)
  //  def denom: Int = y / gcd(x, y)

  //  val numer: Int = x / gcd(x, y)
  //  val denom: Int = y / gcd(x, y)

  def numer: Int = x
  def denom: Int = y

  def <(that: Rational): Boolean =
    numer * that.denom < that.numer * denom

  def max(that: Rational): Rational =
    if (this < that) that else this

  def +(that: Rational): Rational =
    new Rational(
      numer * that.denom + that.numer * denom,
      denom * that.denom
    )

  def unary_- : Rational =
    new Rational(-numer, denom)

  def -(that: Rational): Rational =
    this + -that

  override def toString: String = {
    val g = abs(gcd(numer, denom))
    numer / g + "/" + denom / g
  }
}
