Select branch_id, sum(salary) as total
From employees
Group by branch_id