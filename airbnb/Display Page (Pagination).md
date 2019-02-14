### Display Page (Pagination)

#### Problem statement
>You’re given an array of CSV strings representing search results. Results are sorted by a score initially. A
given host may have several listings that show up in these results. Suppose we want to show 12 results
per page, but we don’t want the same host to dominate the results. Write a function that will reorder
the list so that a host shows up at most once on a page if possible, but otherwise preserves the ordering.
Your program should return the new array and print out the results in blocks representing the pages.
Input: An array of csv strings, with sort score number of results per page. example:
"host_id,listing_id,score,city"
"1,28,300.1,San Francisco"