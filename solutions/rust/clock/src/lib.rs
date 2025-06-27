const MINUTES_IN_DAY: i32 = 24 * 60;

#[derive(Debug)]
pub struct Clock {
    // domain of minutes is 0 - MINUTES_IN_DAY
    minutes: u16,
}

fn add_minutes_mod_day(minutes1: i32, minutes2: i32) -> i32 {
    (((minutes1 + minutes2) % MINUTES_IN_DAY) + MINUTES_IN_DAY) % MINUTES_IN_DAY
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let total_minutes = add_minutes_mod_day(hours * 60, minutes);

        Clock {
            minutes: total_minutes as u16
        }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {

        Clock {
            minutes: add_minutes_mod_day(self.minutes as i32, minutes) as u16,
        }
    }
}

use std::fmt;
impl fmt::Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{:0>2}:{:0>2}", self.minutes / 60, self.minutes % 60)
    }
}

use std::cmp::PartialEq;
impl PartialEq for Clock {
    fn eq(&self, other: &Self) -> bool {
        self.minutes == other.minutes
    }

    fn ne(&self, other: &Self) -> bool {
        self.minutes != other.minutes
    }
}