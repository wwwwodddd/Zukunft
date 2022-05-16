gets.to_i.times{
	a, b, m = gets.split.map &:to_i;
	p a.pow(b, m);
}