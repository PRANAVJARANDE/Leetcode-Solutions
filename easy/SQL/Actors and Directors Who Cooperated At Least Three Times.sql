SELECT DISTINCT a.actor_id,a.director_id 
FROM ActorDirector as a
WHERE (
    SELECT COUNT(*)
    FROM ActorDirector as aa
    WHERE aa.actor_id=a.actor_id AND aa.director_id=a.director_id
)>=3;
