const MINUTES_IN_DAY: i32 = 24 * 60;

#[derive(Debug)]
pub struct Clock {
    // domain of minutes is 0 - MINUTES_IN_DAY
    minutes: u16,
}



fn add_minutes_mod_day(minutes1: &i32, minutes2: &i32) -> i32 {
    (((minutes1 + minutes2) % MINUTES_IN_DAY) + MINUTES_IN_DAY) % MINUTES_IN_DAY
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        // todo!("Construct a new Clock from {hours} hours and {minutes} minutes");

        // additional hours from |minutes| > 60
        let minutes_mod = minutes % 60;
        let adjusted_hours = if minutes_mod.is_negative() {
            minutes / 60 - 1 // roll back an hour
        } else {
            minutes / 60
        };

        let hours_in_minutes = ((((hours + adjusted_hours) % 24) + 24) % 24) * 60;
        let adjusted_minutes = ((minutes_mod) + 60) % 60;

        Clock {
            minutes: add_minutes_mod_day(&hours_in_minutes, &adjusted_minutes) as u16,
        }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        // todo!("Add {minutes} minutes to existing Clock time");
        Clock {
            minutes: add_minutes_mod_day(&self.minutes.into(), &minutes) as u16,
        }
    }
}

use std::fmt;
impl fmt::Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        // todo!("convert to string using write!()")
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