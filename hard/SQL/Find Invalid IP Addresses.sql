WITH temp1 AS (
    SELECT ip,COUNT(log_id) as cnt,
        LENGTH(ip)-LENGTH(REPLACE(ip, '.', '')) AS dot_count,
        SUBSTRING_INDEX(ip, '.', 1) AS octet1,
        SUBSTRING_INDEX(SUBSTRING_INDEX(ip, '.', 2), '.', -1) AS octet2,
        SUBSTRING_INDEX(SUBSTRING_INDEX(ip, '.', 3), '.', -1) AS octet3,
        SUBSTRING_INDEX(SUBSTRING_INDEX(ip, '.', 4), '.', -1) AS octet4
        FROM logs
        GROUP BY ip
    )
SELECT ip,cnt as invalid_count
FROM temp1
WHERE dot_count!=3 OR
(LENGTH(octet1)!=1 AND SUBSTRING(octet1,1,1)="0") OR
(LENGTH(octet2)!=1 AND SUBSTRING(octet2,1,1)="0") OR
(LENGTH(octet3)!=1 AND SUBSTRING(octet3,1,1)="0") OR
(LENGTH(octet4)!=1 AND SUBSTRING(octet4,1,1)="0") OR
CAST(octet1 AS UNSIGNED) > 255 OR
CAST(octet2 AS UNSIGNED) > 255 OR
CAST(octet3 AS UNSIGNED) > 255 OR
CAST(octet4 AS UNSIGNED) > 255
order BY invalid_count DESC, ip DESC
