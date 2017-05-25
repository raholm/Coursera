package quickcheck

import org.scalacheck.Arbitrary._
import org.scalacheck.Gen._
import org.scalacheck.Prop._
import org.scalacheck._

import scala.annotation.tailrec

abstract class QuickCheckHeap extends Properties("Heap") with IntHeap {

  lazy val genHeap: Gen[H] = for {
    item <- arbitrary[A]
    heap <- frequency((1, const(empty)), (4, genHeap))
  } yield insert(item, heap)

  implicit lazy val arbHeap: Arbitrary[H] = Arbitrary(genHeap)

  @tailrec
  private def getOrder(h: H, order: Seq[A]): Seq[A] = {
    if (isEmpty(h)) order
    else {
      val minVal = findMin(h)
      getOrder(deleteMin(h), order :+ minVal)
    }
  }

  property("gen1") = forAll { (h: H) =>
    val m = if (isEmpty(h)) 0 else findMin(h)
    findMin(insert(m, h)) == m
  }

  property("minOfTwoInsertsToEmptyHeap") = forAll { (v1: A, v2: A) =>
    val minVal = v1 min v2
    val heap = meld(insert(v1, empty), insert(v2, empty))
    findMin(heap) == minVal
  }

  property("minOfMeldTwoHeaps") = forAll { (h1: H, h2: H) =>
    findMin(meld(h1, h2)) == Math.min(findMin(h1), findMin(h2))
  }

  property("deleteOneElementHeap") = forAll { (v: A) =>
    val heap = insert(v, empty)
    isEmpty(deleteMin(heap))
  }

  property("sortedOrder") = forAll { (h: H) =>
    val order = getOrder(h, Seq.empty)
    order == order.sorted
  }

  property("sortedOrderAfterMeld") = forAll { (h1: H, h2: H) =>
    val order = getOrder(meld(h1, h2), Seq.empty)
    order == order.sorted
  }

  property("unchangedMeld") = forAll { (h1: H, h2: H) =>
    val meld1 = meld(h1, h2)
    val minVal = findMin(h1)
    val meld2 = meld(deleteMin(h1), insert(minVal, h2))
    val order1 = getOrder(meld1, Seq.empty)
    val order2 = getOrder(meld2, Seq.empty)
    order1 == order2
  }
}
