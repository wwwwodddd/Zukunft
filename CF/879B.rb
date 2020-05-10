n, k = gets.split.map &:to_i
b, c = 0, 0
gets.split.map(&:to_i).each{|v|
	c = b > 0 ? (b > v ? c + 1 : 1) : 0
	b = [b, v].max
	c == k && break
}
p b