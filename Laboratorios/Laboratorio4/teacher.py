from person import Person
class Teacher(Person):
    def __init__(self, name, age, employee_id):
        super().__init__(name, age)
        self.employee_id = employee_id
        self.courses_taught = []

    def assign_course(self, course):
        self.courses_taught.append(course)

    def display_info(self):
        super().display_info()
        print(f"Employee ID: {self.employee_id}\nCourses taught: {', '.join(self.courses_taught)}")
