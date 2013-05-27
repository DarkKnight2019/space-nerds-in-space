

module little_pod()
{
	scale(v = [1, 1.5, 1])
		sphere(r = 1.5, center = true);
}

module main_fuselage()
{
	union() {
		union() {
			rotate(a = 90, v = [1, 0, 0]) {
				scale(v = [1, 0.5, 1])
					cylinder(h = 20, r1 = 3.5, r2 = 2.5, center = true);
			}
			translate(v = [0, 5, 0.8])
				sphere(r = 2.5, center = true);
			translate(v = [0, -5, 0.5])
				sphere(r = 1.8, center = true);
		}
		translate(v = [0, 10, 0])
			sphere(r = 3.5, center = true);
		translate(v = [0, -10, 0])
			sphere(r = 1.8, center = true);
		translate(v = [4, 10, 0])
			little_pod();
	}
}

module sub_fuselage()
{
	union() {
		rotate(a = 90, v = [1, 0, 0]) {
			scale(v = [1, 1.2, 1])
				cylinder(h = 13, r1 = 0.7, r2 = 0.5, center = true);
		}
		translate(v = [0, 2, 0.5])
			sphere(r = 1.3, center = true);
	}
}

module ship()
{
	rotate(a = -90, v = [0, 0, 1])
	union() {
		translate(v = [0, 0, -2.5])
			sub_fuselage();
		main_fuselage();
	}
}

$fn = 6;
ship();

