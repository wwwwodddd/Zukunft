n, k = gets.split.map &:to_i
a = gets.split.map(&:to_i).sort.slice(n - k ... n)
s = 0.0
a.each{|i| s = (s + i) / 2}
p s
