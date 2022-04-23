SELECT
    `name` 
FROM
    `distrib`
WHERE
    `id_distrib` IN (42, 71, 88, 89, 90)
OR 
    `id_distrib` BETWEEN 62 AND 69
OR 
    (LENGTH(name) - LENGTH(REPLACE(LOWER(name), 'y', '')) = 2)
LIMIT 2, 5;
