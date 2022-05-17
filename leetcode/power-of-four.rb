# @param {Integer} num
# @return {Boolean}
def is_power_of_four(num)
    if /^10*$/ =~ num.to_s(4) then
        return true
    else
        return false
    end
end