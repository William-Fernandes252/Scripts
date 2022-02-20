import requests
from bs4 import BeautifulSoup


url = 'https://stackoverflow.com/questions/tagged/python'
response = requests.get(url)
html = BeautifulSoup(response.text, 'html.parser')

print('\nCurrent Questions for Python in Stack Overflow.\n')
for question in html.select('.s-post-summary'):
    title = question.select_one('.s-link')
    date = question.select_one('.relativetime')
    votes = question.select_one('.s-post-summary--stats-item-number')
    print(
        f'Relative time: {date.text}',
        f'Title: {title.text}',
        f'Votes: {votes.text}',
        sep='\n'
    )
    print()