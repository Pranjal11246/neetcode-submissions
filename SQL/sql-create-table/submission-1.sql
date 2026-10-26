create table videos(
    id integer,
    name varchar(50),
    created_at date,
    published boolean
)







-- Do not modify below this line --
SELECT table_name, column_name, data_type
FROM information_schema.columns
WHERE table_name = 'videos';
