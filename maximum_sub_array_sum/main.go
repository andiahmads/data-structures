package main

import (
	"fmt"
)

func main() {
	arr := []int{-1, 2, 4, -3, 5, 2, -5, 2}
	lendata := len(arr)
	res := maximum_subarray_sum(arr, lendata)
	fmt.Println("result from golang: ", res)
}

func maximum_subarray_sum(arr []int, length int) int {
	best := 0
	for a := 0; a < length; a++ {
		sum := 0
		for b := a; b < length; b++ {
			sum += arr[b]
			best = max(best, sum)
		}
	}
	return best
}
