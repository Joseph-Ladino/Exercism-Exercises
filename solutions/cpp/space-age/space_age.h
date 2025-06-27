#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

namespace space_age {

	struct space_age {
		double s;

		int seconds() const { return s * 31557600; }
		double on_mercury() const { return s / 0.2408467; }
		double on_venus() const { return s / 0.61519726; }
		double on_earth() const { return s; }
		double on_mars() const { return s / 1.8808158; }
		double on_jupiter() const { return s / 11.862615; }
		double on_saturn() const { return s / 29.447498; }
		double on_uranus() const { return s / 84.016846; }
		double on_neptune() const { return s / 164.79132; }

		space_age(double num) { s = num / 31557600; }
	};

}  // namespace space_age

#endif // SPACE_AGE_H