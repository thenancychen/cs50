-- Keep a log of any SQL queries you execute as you solve the mystery.
-- access the interview transcript
SELECT transcript 
FROM interviews
WHERE transcript LIKE "%bakery%"
AND month = 7
AND day = 28;

/* 
Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. 
If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
| I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, 
I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
| As the thief was leaving the bakery, they called someone who talked to them for less than a minute. 
In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. 
The thief then asked the person on the other end of the phone to purchase the flight ticket. |
| I'm the bakery owner, and someone came in, suspiciously whispering into a phone for about half an hour. They never bought anything.
*/

-- access crime scene reports 
SELECT description
FROM crime_scene_reports 
WHERE month = 7
AND day = 28
AND street = "Humphrey Street";

-- access the bakery security logs during this day 
SELECT license_plate
FROM bakery_security_logs
WHERE activity = "exit"
AND month = 7
AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 25;

-- find people with the license plates from bakery
SELECT name
FROM people
WHERE license_plate IN
(
   SELECT license_plate
    FROM bakery_security_logs
    WHERE activity = "exit"
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute BETWEEN 15 AND 25
);

/* 
license plate
  name   |
+---------+
| Vanessa |
| Barry   |
| Iman    |
| Sofia   |
| Luca    |
| Diana   |
| Kelsey  |
| Bruce 
*/

-- access ATM transactions from interview #2
SELECT account_number
FROM atm_transactions
WHERE atm_location = "Leggett Street"
AND month = 7
AND day = 28
AND year = 2021
AND transaction_type = "withdraw"; 

-- figure out which person's account number this is from ATM withdrawal
SELECT name
FROM people
WHERE id IN
(
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
    (
        SELECT account_number
        FROM atm_transactions
        WHERE atm_location = "Leggett Street"
        AND month = 7
        AND day = 28
        AND year = 2021
        AND transaction_type = "withdraw"
    )
);
/* 
bank account
--------+
|  name   |
+---------+
| Kenny   |
| Iman    |
| Benista |
| Taylor  |
| Brooke  |
| Luca    |
| Diana   |
| Bruce   |
*/

-- access calls of people who talked to them for less than a minute
SELECT name
FROM people
WHERE phone_number IN
(
    SELECT caller
    FROM phone_calls
    WHERE month = 7
    AND day = 28
    AND year = 2021
    AND duration < 60
)
/* 
phone calls
  name   |
+---------+
| Kenny   |
| Sofia   |
| Benista |
| Taylor  |
| Diana   |
| Kelsey  |
| Bruce   |
| Carina 
*/

-- access earliest flight 
SELECT name
FROM people
WHERE passport_number IN
(
    SELECT passport_number
    FROM passengers
    WHERE flight_id IN
    (
        SELECT id
        FROM flights
        WHERE month = 7
        AND day = 29
        AND year = 2021
        AND origin_airport_id = 
        (
            SELECT id
            FROM airports
            WHERE city = "Fiftyville"
        )
        ORDER BY hour, minute ASC
        LIMIT 1
    )
);
/* 
earliest flight ID
+----+
| id |
+----+
| 36 |

passport number
+---------+
|  name   |
+---------+
| Kenny   |
| Iman    |
| Benista |
| Taylor  |
| Brooke  |
| Luca    |
| Diana   |
| Bruce   |
*/

-- figure out who accomplice is
SELECT name 
FROM people
WHERE phone_number =
(
    SELECT receiver
    FROM phone_calls
    WHERE month = 7
    AND day = 28
    AND year = 2021
    AND duration < 60
    AND caller = 
    (
        SELECT phone_number
        FROM people
        WHERE name = "Bruce"
    )
);

/*
| name  |
+-------+
| Robin |
*/

-- city where Bruce escaped to
SELECT city
FROM airports
WHERE id IN 
(
    SELECT destination_airport_id
    FROM flights
    WHERE id = 36
);
/*
+---------------+
|     city      |
+---------------+
| New York City |
+---------------+
*/