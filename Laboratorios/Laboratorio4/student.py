from person import Person
class Student(Person):
    def __init__(self, name, age, student_id):
        super().__init__(name, age)
        self.student_id = student_id
        self.courses = []

    def enroll_course(self, course):
        self.courses.append(course)

    def display_info(self):
        super().display_info()
        print(f"Student ID: {self.student_id}\nCourses: {', '.join(self.courses)}")
