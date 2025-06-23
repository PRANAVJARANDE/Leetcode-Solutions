SELECT * FROM products  
WHERE description LIKE '% SN___[0-9]-____' 
   OR description LIKE '% SN___[0-9]-____ %'         
   OR description LIKE 'SN___[0-9]-____ %'
