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
