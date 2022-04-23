SELECT title, summary
FROM film
WHERE LOCATE('42', summary) OR LOCATE('42', title)
ORDER BY duration ASC;
