# @param {Integer} n
# @return {Boolean}
def is_power_of_three(n)
    if /^10*$/ =~ n.to_s(3) then
        return true
    else
        return false
    end
end