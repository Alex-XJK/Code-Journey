# @param {String} s
# @return {Integer}
def remove_palindrome_sub(s)
    if s == s.reverse
        return 1
    else
        return 2
    end
end