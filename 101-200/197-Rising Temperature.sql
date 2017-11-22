select w2.Id from weather w2
join weather w1
on DATEDIFF(w2.date, w1.date) = 1
where w1.Temperature<w2.Temperature