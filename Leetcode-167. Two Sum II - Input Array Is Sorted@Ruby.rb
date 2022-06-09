# @param {Integer[]} numbers
# @param {Integer} target
# @return {Integer[]}
def two_sum(numbers, target)
    i, j = 0, numbers.size-1
    while i < j
        sum = numbers[i] + numbers[j]
        cmp = sum <=> target
        case cmp
        when 1
            j -= 1
        when -1
            i += 1
        else
            return [i+1, j+1]
        end
    end
end