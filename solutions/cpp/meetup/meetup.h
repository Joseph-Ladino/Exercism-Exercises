#if !defined(MEETUP_H)
#define MEETUP_H
#include <boost/date_time/gregorian/gregorian.hpp>

#define TEENTH(day) return first_day_of_the_week_after(day).get_date(date(y, m, 12));
#define FDAW(day) return first_day_of_the_week_in_month(day, m).get_date(y);
#define LDAW(day) return last_day_of_the_week_in_month(day, m).get_date(y);
#define NDAW(day, week) return nth_day_of_the_week_in_month(nth_day_of_the_week_in_month::##week, day, m).get_date(y);

using namespace boost::gregorian;

namespace meetup {

	struct scheduler {

		greg_month m = Monday;
		greg_year y = 2020;

		date sunteenth   () const { TEENTH(Sunday   ) }
		date monteenth   () const { TEENTH(Monday   ) }
		date tuesteenth  () const { TEENTH(Tuesday  ) }
		date wednesteenth() const { TEENTH(Wednesday) }
		date thursteenth () const { TEENTH(Thursday ) }
		date friteenth   () const { TEENTH(Friday   ) }
		date saturteenth () const { TEENTH(Saturday ) }


		date first_sunday   () const { FDAW(Sunday   ) }
		date first_monday   () const { FDAW(Monday   ) }
		date first_tuesday  () const { FDAW(Tuesday  ) }
		date first_wednesday() const { FDAW(Wednesday) }
		date first_thursday () const { FDAW(Thursday ) }
		date first_friday   () const { FDAW(Friday   ) }
		date first_saturday () const { FDAW(Saturday ) }


		date second_sunday   () const { NDAW(Sunday,    second) }
		date second_monday   () const { NDAW(Monday,    second) }
		date second_tuesday  () const { NDAW(Tuesday,   second) }
		date second_wednesday() const { NDAW(Wednesday, second) }
		date second_thursday () const { NDAW(Thursday,  second) }
		date second_friday   () const { NDAW(Friday,    second) }
		date second_saturday () const { NDAW(Saturday,  second) }


		date third_sunday   () const { NDAW(Sunday,    third) }
		date third_monday   () const { NDAW(Monday,    third) }
		date third_tuesday  () const { NDAW(Tuesday,   third) }
		date third_wednesday() const { NDAW(Wednesday, third) }
		date third_thursday () const { NDAW(Thursday,  third) }
		date third_friday   () const { NDAW(Friday,    third) }
		date third_saturday () const { NDAW(Saturday,  third) }


		date fourth_sunday   () const { NDAW(Sunday,    fourth) }
		date fourth_monday   () const { NDAW(Monday,    fourth) }
		date fourth_tuesday  () const { NDAW(Tuesday,   fourth) }
		date fourth_wednesday() const { NDAW(Wednesday, fourth) }
		date fourth_thursday () const { NDAW(Thursday,  fourth) }
		date fourth_friday   () const { NDAW(Friday,    fourth) }
		date fourth_saturday () const { NDAW(Saturday,  fourth) }


		date last_sunday   () const { LDAW(Sunday   ) }
		date last_monday   () const { LDAW(Monday   ) }
		date last_tuesday  () const { LDAW(Tuesday  ) }
		date last_wednesday() const { LDAW(Wednesday) }
		date last_thursday () const { LDAW(Thursday ) }
		date last_friday   () const { LDAW(Friday   ) }
		date last_saturday () const { LDAW(Saturday ) }


		scheduler(greg_month month, greg_year year) {
			m = month;
			y = year;
		}
	};

}  // namespace meetup

#endif // MEETUP_H