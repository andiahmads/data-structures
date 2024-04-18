fn buble_sort(arr: &mut [i32]) -> &mut [i32] {
    let n = arr.len();
    for _ in 0..n {
        for j in 0..n - 1 {
            if arr[j] > arr[j + 1] {
                arr.swap(j, j + 1);
            }
        }
    }

    return arr;
}

fn main() {
    let mut arr: [i32; 8] = [1, 3, 8, 2, 9, 2, 5, 6];

    let result = buble_sort(&mut arr);

    println!("{:?}", result);
}
