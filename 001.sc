object Solution {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
      val v = nums.zipWithIndex.toMap
      val r = nums.indices.indexWhere(i => v.get(target-nums(i)).exists(_ != i))
      if (r == -1) return Array(-1, -1)
      return Array(r, v(target-nums(r)))
  }
}
