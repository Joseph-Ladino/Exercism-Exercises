use rand::Rng;


// https://en.wikipedia.org/wiki/Modular_exponentiation#Pseudocode
fn mod_exponent(base: &u64, exponent: &u64, modulus: &u64) -> u64 {
    if *modulus == 1 {
        return 0;
    }

    let mut result:u128 = 1;
    let mut base:u128 = (*base % modulus).into();
    let mut exponent:u128 = (*exponent).into();
    let modulus:u128 = (*modulus).into();

    while exponent > 0 {
        if exponent % 2 == 1 {
            result = (result * base) % modulus;
        }

        exponent >>= 1;
        base = (base * base) % modulus;
    }

    result as u64
}

pub fn private_key(p: u64) -> u64 {
    // todo!("Pick a private key greater than 1 and less than {p}");
    rand::thread_rng().gen_range(2..p)
}

pub fn public_key(p: u64, g: u64, a: u64) -> u64 {
    // todo!("Calculate public key using prime numbers {p} and {g}, and private key {a}")
    mod_exponent(&g, &a, &p)
}

pub fn secret(p: u64, b_pub: u64, a: u64) -> u64 {
    // todo!("Calculate secret key using prime number {p}, public key {b_pub}, and private key {a}")
    mod_exponent(&b_pub, &a, &p)
}
