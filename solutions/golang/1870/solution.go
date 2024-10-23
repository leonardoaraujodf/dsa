var limit float64
func minSpeedOnTime(dist []int, hour float64) int {
    if len(dist) > int(math.Ceil(hour)) {
        return -1
    }

    limit = hour
    left := 1
    right := int(math.Pow(10, 7))
    for left <= right {
        mid := left + (right - left) / 2
        if check(float64(mid), dist) {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }

    return left
}

func check(speed float64, dist []int) bool {
    var actualHours float64
    actualHours = 0
    for _, dt := range dist {
        fdt := float64(dt)
        actualHours = math.Ceil(actualHours)
        actualHours += fdt / speed
    }
    return actualHours <= limit
}
