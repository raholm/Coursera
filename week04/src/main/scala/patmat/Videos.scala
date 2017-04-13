/**
  * Created by java on 4/13/17.
  */

object Week04 {
  def main(args: Array[String]): Unit = {
    println("Week 4")
  }

  abstract class Nat {
    def isZero: Boolean
    def predecessor: Nat
    def successor: Nat = new Succ(this)
    def +(that: Nat): Nat
    def -(that: Nat): Nat
  }

  object Zero extends Nat {
    override def isZero: Boolean = true

    override def predecessor: Nat = throw new Error("Zero.predecessor")

    override def +(that: Nat): Nat = that

    override def -(that: Nat): Nat = {
      if (that.isZero) this
      else throw new Error("Zero.-")
    }
  }

  class Succ(n: Nat) extends Nat {
    override def isZero: Boolean = false

    override def predecessor: Nat = n

    override def +(that: Nat): Nat = new Succ(predecessor + that)

    override def -(that: Nat): Nat = {
      if (that.isZero) this
      else predecessor - that.predecessor
    }
  }
}