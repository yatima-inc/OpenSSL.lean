define nb
	shell nix build .#test-debug -L
	file result/bin/tests
end
define nbr
	nb
	run
end
