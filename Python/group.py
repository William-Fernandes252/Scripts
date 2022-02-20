from itertools import groupby, tee

students_class = [
    {'name': 'Luiz', 'score': 'A'},
    {'name': 'Letícia', 'score': 'B'},
    {'name': 'Fabrício', 'score': 'A'},
    {'name': 'Rosemary', 'score': 'C'},
    {'name': 'Joana', 'score': 'D'},
    {'name': 'João', 'score': 'A'},
    {'name': 'Eduardo', 'score': 'B'},
    {'name': 'André', 'score': 'C'},
    {'name': 'Anderson', 'score': 'B'},
]


order = lambda student: student['score']

students_class.sort(key=order)
grouped_students = groupby(students_class, order)

# Com tee
for score, students in grouped_students:
  v1, v2 = tee(students)

  print(f'score: {score}')

  for student in v1:
    print(f'\t{student}')

  qty = len(list(v2))
  print(f'\t{qty} students scored {score}')