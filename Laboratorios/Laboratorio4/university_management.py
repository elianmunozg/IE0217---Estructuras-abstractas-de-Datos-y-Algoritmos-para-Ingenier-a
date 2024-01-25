from student import Student
from teacher import Teacher
from course import Course

student1 = Student("Esteban", 43, "B30754")
student2 = Student("María", 28, "B51349")

teacher1 = Teacher("Jorge Romero", 65, "123456")
teacher2 = Teacher("Luis Díaz Marín", 61, "55555")

course1 = Course("IE0217", "DSA")
course2 = Course("TE0632", "CDI")

student1.enroll_course(course1.course_code)
student1.enroll_course(course2.course_code)

teacher1.assign_course(course1.course_code)
teacher2.assign_course(course2.course_code)

student1.display_info()
teacher1.display_info()
