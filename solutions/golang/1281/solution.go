var numberOfPeople int
func maximizeSweetness(sweetness []int, k int) int {
    numberOfPeople = k + 1
    left := math.MaxInt
    right := 0
    // Get minimum element and the sum of all sweetness
    for _, num := range sweetness {
        if left > num {
            left = num
        }
        right += num
    }

    right /= numberOfPeople
    for left <= right {
        mid := left + (right - left) / 2
        if check(mid, sweetness) {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }

    return right
}

func check(minSweetness int, sweetness []int) bool {
    peopleWithChocolate := 0
    currSweetness := 0
    for _, s := range sweetness {
        currSweetness += s
        if currSweetness >= minSweetness {
            currSweetness = 0
            peopleWithChocolate++
        }
    }

    return peopleWithChocolate >= numberOfPeople
}
