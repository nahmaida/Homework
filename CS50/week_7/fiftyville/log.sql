-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Find the report from the crime scene.
SELECT
    id,
    description
FROM
    crime_scene_reports
WHERE
    year = 2023
    AND month = 7
    AND day = 28
    AND street = 'Humphrey Street';

-- The report mentioned three interviews with witnesses. Find said interviews by date and mention of bakery.
-- The robbery took place on 10:15 am.
SELECT
    name,
    transcript
FROM
    interviews
WHERE
    transcript LIKE '%bakery%'
    AND year = 2023
    AND month = 7
    AND day = 28;

-- The first interview mentioned the thief driving away within ten minutes of the robbery.
-- Check bakery security logs for cars exiting in that timeframe.
SELECT
    activity,
    license_plate
FROM
    bakery_security_logs
WHERE
    year = 2023
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute >= 15
    AND minute <= 25;

-- RESULTS
-- exit|5P2BI95
-- exit|94KL13X
-- exit|6P58WS2
-- exit|4328GD8
-- exit|G412CB7
-- exit|L93JTIZ
-- exit|322W7JE
-- exit|0NTHK55
--The second interview mentioned the thief withdrawing money from an ATM on Leggett Street
-- Check ATM logs for suspects' bank account numbers
SELECT
    id,
    account_number,
    transaction_type,
    amount
FROM
    atm_transactions
WHERE
    year = 2023
    AND month = 7
    AND day = 28
    AND atm_location = 'Leggett Street';

-- RESULTS
-- 246|28500762|withdraw|48
-- 264|28296815|withdraw|20
-- 266|76054385|withdraw|60
-- 267|49610011|withdraw|50
-- 269|16153065|withdraw|80
-- 275|86363979|deposit|10 << IGNORE
-- 288|25506511|withdraw|20
-- 313|81061156|withdraw|30
-- 336|26013199|withdraw|35
-- The last interview mentioned the thief planning to purchase a flight ticket for the earliest flight on the next day.
-- Check Fiftyville's airport id.
SELECT
    *
FROM
    airports
WHERE
    city = 'Fiftyville';

-- RESULTS
-- 8|CSF|Fiftyville Regional Airport|Fiftyville
-- Check the first outgoing flight on the 29th
SELECT
    *
FROM
    flights
WHERE
    origin_airport_id = 8
    AND year = 2023
    AND month = 7
    AND day = 29
ORDER BY
    hour
LIMIT
    1;

-- RESULTS
-- 36|8|4|2023|7|29|8|20
-- Determine destination city
SELECT
    city
FROM
    airports
WHERE
    id = 4;

-- RESULTS
-- New York City
-- Determine potential suspects
-- Find matches in passengers' passport numbers and license plates' owners' passport numbers
SELECT
    *
FROM
    passengers
WHERE
    flight_id = 36
    AND passport_number IN (
        SELECT
            passport_number
        FROM
            people
        WHERE
            license_plate IN (
                SELECT
                    license_plate
                FROM
                    bakery_security_logs
                WHERE
                    year = 2023
                    AND month = 7
                    AND day = 28
                    AND hour = 10
                    AND minute >= 15
                    AND minute <= 25
                    AND activity = 'exit'
            )
    );

-- RESULTS
-- 36|1695452385|3B
-- 36|5773159633|4A
-- 36|8294398571|6C
-- 36|8496433585|7B
-- Compare against suspected bank accounts and retieve suspects' data.
SELECT
    *
FROM
    people
WHERE
    (
        passport_number = 1695452385
        OR passport_number = 5773159633
        OR passport_number = 8294398571
        OR passport_number = 8496433585
    )
    AND id IN (
        SELECT
            person_id
        FROM
            bank_accounts
        WHERE
            account_number IN (
                SELECT
                    account_number
                FROM
                    atm_transactions
                WHERE
                    year = 2023
                    AND month = 7
                    AND day = 28
                    AND atm_location = 'Leggett Street'
            )
    );

-- RESULTS
-- 467400|Luca|(389) 555-5198|8496433585|4328GD8
-- 686048|Bruce|(367) 555-5533|5773159633|94KL13X
-- We almost got them.
-- Lastly, determine who's the thief and who's the accomplice.
SELECT
    *
FROM
    phone_calls
WHERE
    year = 2023
    AND month = 7
    AND day = 28
    AND duration <= 60;

-- RESULTS
-- 221|(130) 555-0289|(996) 555-8899|2023|7|28|51
-- 224|(499) 555-9472|(892) 555-8872|2023|7|28|36
-- 233|(367) 555-5533|(375) 555-8161|2023|7|28|45 << MATCH
-- 234|(609) 555-5876|(389) 555-5198|2023|7|28|60
-- 251|(499) 555-9472|(717) 555-1342|2023|7|28|50
-- 254|(286) 555-6063|(676) 555-6554|2023|7|28|43
-- 255|(770) 555-1861|(725) 555-3243|2023|7|28|49
-- 261|(031) 555-6622|(910) 555-3251|2023|7|28|38
-- 279|(826) 555-1652|(066) 555-9701|2023|7|28|55
-- 281|(338) 555-6650|(704) 555-2131|2023|7|28|54
-- Got him. Bruce is the thief.
-- Lastly, determine the accomplice.
SELECT
    *
FROM
    people
WHERE
    phone_number = '(375) 555-8161';

-- RESULTS
-- 864400|Robin|(375) 555-8161||4V16VO0
-- Case closed. Thief: Bruce. City: NYC. Accomplice: Robert.