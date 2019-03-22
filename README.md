# pictureboardwall.c
Some examples in c

### Name your methods carefully

The following method checks if the passed integer is a power of two: 

	bool is_power_of_two(int num) {
	  return ((num & (num - 1)) != 0);
	}

So, i started to test it, eg. as follows:

    num = strtoll(argv[i], NULL, 10);
    if(!is_power_of_two(num)) {
      printf("Apparently not a power of two: %d\n", num);
    }


I was surprised about the output:

	➜  ./check_if_power_of_two 2 4 6 8
	Apparently not a power of two: 2
	Apparently not a power of two: 4
	Apparently not a power of two: 8

Solution: The term `(num & (num - 1)) != 0` checks if the `num` is
**not** a power of two, so the naming `check_if_power_of_two` is
stating the opposite!

Fix looks like:

	bool is_power_of_two(int num) {
	  return ((num & (num - 1)) == 0);
	}

Looks better now:

	✗ ./check_if_power_of_two 2 4 6 8 
	Apparently not a power of two: 6


