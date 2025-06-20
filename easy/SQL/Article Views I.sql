SELECT distinct v.author_id as id 
FROM Views as v
WHERE v.author_id=v.viewer_id
ORDER BY id 
