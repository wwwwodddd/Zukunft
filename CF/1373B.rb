gets.to_i.times{s=gets;puts [s.count('0'),s.count('1')].min%2>0?:DA:'NET'}
#gets.to_i.times{gets;puts [$_.count('0'),$_.count('1')].min%2>0?:DA:'NET'}
#gets.to_i.times{gets;puts [:NET,:DA][[$_.count('0'),$_.count('1')].min%2]}