package main

import "fmt"

func bubleSort(arr []int, n int) []int {
	for i := 0; i < n; i++ {
		for j := 0; j < n-1; j++ {
			if arr[j] > arr[j+1] {
				temp := arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = temp
			}
		}
	}
	return arr
}

func main() {
	arr := []int{1, 3, 8, 2, 9, 2, 5, 6}
	length := len(arr)
	result := bubleSort(arr, length)
	fmt.Println(result)
}
