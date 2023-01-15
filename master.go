package main

import (
	"math"
)

func abs(a int) int {
	return int(math.Abs(float64(a)))
}

func pow(p, q int) int {
	return int(math.Pow(float64(p), float64(q)))
}

func min(nums ...int) int {
	if len(nums) == 0 {
		panic("function min() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Min(float64(res), float64(nums[i])))
	}
	return res
}

func max(nums ...int) int {
	if len(nums) == 0 {
		panic("function max() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Max(float64(res), float64(nums[i])))
	}
	return res
}

func main() {
	// multi input
	// var x, n int
	// fmt.Scan(&x, &n)

	// n input
	// var n int
	// fmt.Scan(&n)
	// t := make([]int, n)
	// for i := 0; i < n; i++ {
	// 	fmt.Scan(&t[i])
	// }

	// for statement
	// sum := 0
	// for i := 0; i < 10; i++ {
	// 	sum += i
	// }

	// if statement
	// x := 100
	// if x == 50 {
	// 	fmt.Println("Germany")
	// } else if x == 100 {
	// 	fmt.Println("Japan")
	// } else {
	// 	fmt.Println("Canada")
	// }

}
