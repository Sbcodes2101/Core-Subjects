Show first name, last name, and gender of patients whose gender is 'M'

SELECT first_name,last_name,gender //column that we need to show 
FROM patients //which table
WHERE gender = 'M' //condition

Show first name and last name of patients who does not have allergies. (null)

select first_name,last_name
FROM patients
where allergies IS NULL

Show first name of patients that start with the letter 'C'

SELECT first_name
fROM patients
where first_name like 'C%'

Show first name and last name of patients that weight within the range of 100 to 120 (inclusive)

SELECT first_name,last_name
FROM patients
WHERE weight>=100 AND weight<=120

Update the patients table for the allergies column. If the patient's allergies is null then replace it with 'NKA'
UPDATE patients
SET allergies = 'NKA'
where allergies IS NULL

Show first name and last name concatinated into one column to show their full name.

SELECT CONCAT(firstname+' '+lastname) AS full_name
FROM patients

<!-- Question on joins -->
Show first name, last name, and the full province name of each patient.

SELECT first_name,last_name,province_name
FROM patients
JOIN province_names
ON province_names.province_id = patients.province_id

Show how many patients have a birth_date with 2010 as the birth year.

SELECT (*) COUNT
FROM patients
WHERE YEAR(birth_date) = 2010

Show the first_name, last_name, and height of the patient with the greatest height.

<!-- first of all query for finding maximum height -->

SELECT MAX(height)
FROM patients

<!-- selecting first_name,last_name and height given satisgying the given conditions -->

SELECT first_name,last_name,height
FROM patients
WHERE height = (
    SELECT MAX(height)
    FROM patients
)


Show all columns for patients who have one of the following patient_ids:
1,45,534,879,1000

SELECT *
FROM patients
WHERE patient_id IN (1,45,534,879,1000)

Show the total number of admissions

SELECT COUNT(*)
FROM admissions 

Show all the columns from admissions where the patient was admitted and discharged on the same day.

SELECT *
FROM admissions
WHERE admission_date = discharge_date

Show the patient id and the total number of admissions for patient_id 579.

SELECT patient_id,COUNT(*)
FROM admissions
WHERE patient_id=579 

Based on the cities that our patients live in, show unique cities that are in province_id 'NS'.

SELECT DISTINCT city AS unique_cities
FROM patients 
WHERE province_id = 'NS'

Write a query to find the first_name, last name and birth date of patients who has height greater than 160 and weight greater than 70

select first_name,last_name,birth_date
FROM patients
WHERE height>160 AND weight>70

Write a query to find list of patients first_name, last_name, and allergies where allergies are not null and are from the city of 'Hamilton'

SELECT first_name,last_name,allergies
FROM patients
WHERE allergies IS NOT null AND city = 'Hamilton'

MEDIUM
Show unique birth years from patients and order them by ascending.

SELECT DISTINCT YEAR(birth_date) AS birth_year
FROM patients
ORDER BY birth_year

Show unique first names from the patients table which only occurs once in the list.

For example, if two or more people are named 'John' in the first_name column then don't include their name in the output list. If only 1 person is named 'Leo' then include them in the output.

<!-- we will group FIRST_NAME together for example all the john together by GROUP_BY clause hving a certain count COUNT(*) = 1-->

SELECT first_name
FROM patients
GROUP_BY first_name
HAVING COUNT(*) = 1

Show patient_id and first_name from patients where their first_name start and ends with 's' and is at least 6 characters long.

SELECT patient_id,first_name
FROM patients
WHERE first_name LIKE 's____%s'

Show patient_id, first_name, last_name from patients whos diagnosis is 'Dementia'.

Primary diagnosis is stored in the admissions table.

SELECT patients.patient_id,first_name,last_name
FROM patients
JOIN admissions
ON admissions.patient_id=patients.patient_id
WHERE admissions.diagnosis = 'Dementia'

Display every patient's first_name.
Order the list by the length of each name and then by alphabetically.

SELECT first_name
FROM patients
ORDER BY LEN(first_name),first_name


Show the total amount of male patients and the total amount of female patients in the patients table.
Display the two results in the same row.

Need one row output Subqueries in SELECT always return a single value per column

SELECT

 (SELECT COUNT(*)
 FROM patients
 WHERE gender='M') AS male_count

 (SELECT COUNT(*)
 FROM patients
 WHERE gender = 'F') AS female_count

 Show first and last name, allergies from patients which have allergies to either 'Penicillin' or 'Morphine'. Show results ordered ascending by allergies then by first_name then by last_name.

SELECT first_name,last_name,allergies
FROM patients
WHERE allergies = 'Penicillin' OR allergies = 'Morphine'
ORDER BY allergies,first_name,last_name

Show the city and the total number of patients in the city.
Order from most to least patients and then by city name ascending.

SELECT city,COUNT(*) AS num_patients
FROM patients
GROUP BY city
ORDER BY num_patients DESC,city ASC

Show first name, last name and role of every person that is either patient or doctor.
The roles are either "Patient" or "Doctor"

SELECT first_name,last_name,'Patient' AS role
FROM patients

UNION ALL

SELECT first_name,last_name,'Doctor' AS role
FROM doctors

Show all allergies ordered by popularity. Remove NULL values from query.

SELECT allergies,COUNT(*) AS total_diagnosis
FROM patients
WHERE allergies IS NOT null
GROUP BY allergies
ORDER BY total_diagnosis DESC


Show all patient's first_name, last_name, and birth_date who were born in the 1970s decade. Sort the list starting from the earliest birth_date.

SELECT first_name,last_name,birth_date
FROM patients
WHERE YEAR(birth_date) BETWEEN 1970 AND 1979
ORDER BY birth_date

We want to display each patient's full name in a single column. Their last_name in all upper letters must appear first, then first_name in all lower case letters. Separate the last_name and first_name with a comma. Order the list by the first_name in decending order
EX: SMITH,jane

SELECT CONCAT(UPPER(last_name),',',LOWER(first_name)) AS new_name_format
FROM patients
ORDER BY first_name DESC

Show the province_id(s), sum of height; where the total sum of its patient's height is greater than or equal to 7,000.

SELECT province_id,SUM(height) AS sum_height
FROM patients
GROUP BY province_id
HAVING sum_height >= 7000
ORDER BY sum_height

Show the difference between the largest weight and smallest weight for patients with the last name 'Maroni'

SELECT MAX(weight) - MIN(weight) AS weight_delta
FROM patients
WHERE lastname = 'Maroni'

Show all of the days of the month (1-31) and how many admission_dates occurred on that day. Sort by the day with most admissions to least admissions.

SELECT DAY(admission_date) AS day_number,COUNT(*) AS number_of_admissions
FROM admission
GROUP BY day_number
ORDER BY number_of_admissions DESC

Show all columns for patient_id 542's most recent admission_date.

SELECT * 
FROM admissions
WHERE patient_id = 542
GROUP BY patient_id
HAVING admission_date = MAX(admission_date)

Show patient_id, attending_doctor_id, and diagnosis for admissions that match one of the two criteria:
1. patient_id is an odd number and attending_doctor_id is either 1, 5, or 19.
2. attending_doctor_id contains a 2 and the length of patient_id is 3 characters.

SELECT patient_id,attending_id,diagnosis
FROM admission
WHERE
(patient_id %2 != 0 AND attending_doctor_id IN (1,5,19))
OR
(attending_doctor_id LIKE '%2%' AND LEN(patient_id)=3)


Show first_name, last_name, and the total number of admissions attended for each doctor.

Every admission has been attended by a doctor.

SELECT first_name,last_name,COUNT(*) AS admissions_total
FROM doctors
JOIN admission
ON admissions.attending_doctor_id = doctors.doctor_id
GROUP BY admissions.attending_doctor_id

For each doctor, display their id, full name, and the first and last admission date they attended.

SELECT
    doctor_id,CONCAT(firstname,'',lastname) AS full_name,
    MAX(admission_date) AS first_admission_date,
    MIN(admission_date) AS
    last_admission_date
FROM doctors
JOIN admissions
ON admissions.attending_doctor_id = doctors.doctor_id
GROUP BY admissions.attending_doctor_id


Display the total amount of patients for each province. Order by descending.


SELECT province_name,COUNT(*) AS patient_count
FROM province_names
JOIN patients
ON province_names.province_id = patients.province_id
GROUP BY province_names.province_id
ORDER BY patient_count DESC

For every admission, display the patient's full name, their admission diagnosis, and their doctor's full name who diagnosed their problem.

select concat(p.first_name,' ',p.last_name) AS patient_name,
diagnosis,
concat(d.first_name,' ',d.last_name) AS doctor_name
from admissions a
JOIN patients p
ON a.patient_id = p.patient_id
JOIN doctors d
ON d.doctor_id = a.attending_doctor_id


display the first name, last name and number of duplicate patients based on their first name and last name.

Ex: A patient with an identical name can be considered a duplicate.

SELECT first_name,last_name,COUNT(*)
FROM patients
GROUP BY first_name,last_name
HAVING COUNT(*) > 1

Display patient's full name,
height in the units feet rounded to 1 decimal,
weight in the unit pounds rounded to 0 decimals,
birth_date,
gender non abbreviated.

Convert CM to feet by dividing by 30.48.
Convert KG to pounds by multiplying by 2.205.

select concat(first_name,' ',last_name) AS patient_name,
		ROUND(height/30.48,1) AS height_feet,
        ROUND(weight*2.205,0) AS weight_pound,
        birth_date,
        CASE
         WHEN gender = 'M' THEN 'Male'
		 ELSE 'Female'
        END as gender_type
FROM patients


Show patient_id, first_name, last_name from patients whose does not have any records in the admissions table. (Their patient_id does not exist in any admissions.patient_id rows.)

SELECT patient_id,first_name,last_name
FROM patients
WHERE
patient_id
NOT IN
(SELECT admissions.patient_id FROM admissions)

Display a single row with max_visits, min_visits, average_visits where the maximum, minimum and average number of admissions per day is calculated. Average is rounded to 2 decimal places.

SELECT
    MAX(no_of_admissions) AS max_visits,
    MIN(no_of_admissions) AS min_visits,
    ROUND(AVG(no_of_admissions),2) AS average_visits
SELECT 
(admission_date,COUNT(*) AS no_of_admissions
FROM admissions
GROUP BY admission_date)

# HARD

Show all of the patients grouped into weight groups.
Show the total amount of patients in each weight group.
Order the list by the weight group decending.

For example, if they weight 100 to 109 they are placed in the 100 weight group, 110-119 = 110 weight group, etc.

SELECT
    COUNT(*) AS patients_in_group,
    FLOOR(weight/10) * 10 AS weight_group
FROM patients
GROUP BY weight_group
ORDER BY weight_group DESC


Show patient_id, weight, height, isObese from the patients table.
Display isObese as a boolean 0 or 1.
Obese is defined as weight(kg)/(height(m)2) >= 30.
weight is in units kg.
height is in units cm.

SELECT patient_id, weight, height
    (CASE
     WHEN (weight/POWER((height/100.0),2)) >= 30 THEN 1
     ELSE 0
    ) AS isObese
FROM patients


Show patient_id, first_name, last_name, and attending doctor's specialty.
Show only the patients who has a diagnosis as 'Epilepsy' and the doctor's first name is 'Lisa'

Check patients, admissions, and doctors tables for required information.

SELECT 
 	p.patient_id,
    p.first_name AS patient_first_name,
    p.last_name AS patient_last_name,
    d.specialty AS attending_doctor_id
FROM admissions a
join doctors d
ON d.doctor_id = a.attending_doctor_id
JOIN patients p
ON a.patient_id = p.patient_id
WHERE a.diagnosis = 'Epilepsy' AND d.first_name = 'Lisa'






