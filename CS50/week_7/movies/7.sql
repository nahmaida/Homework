SELECT
    title,
    rating
FROM
    movies
    JOIN ratings ON id = movie_id
WHERE
    YEAR = 2010
ORDER BY
    rating DESC,
    title;