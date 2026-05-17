def get_valid_input(question):
    while True:
        try:
            value = int(input(question))
            if 1 <= value <= 5:
                return value
            else:
                print("Input must be between 1 and 5. Try again.")
        except:
            print("Invalid input. Please enter a number between 1 and 5.")


def ask_questions():

    # PRODUCTIVITY
    p1 = get_valid_input("Completes assigned tasks on time (1-5): ")
    p2 = get_valid_input("Handles workload efficiently (1-5): ")
    p3 = get_valid_input("Maintains consistent output (1-5): ")

    productivity = (p1 + p2 + p3) / 3

    # QUALITY
    q1 = get_valid_input("Accuracy of work (1-5): ")
    q2 = get_valid_input("Attention to detail (1-5): ")
    q3 = get_valid_input("Follows company standards (1-5): ")

    quality = (q1 + q2 + q3) / 3

    # TEAMWORK
    t1 = get_valid_input("Cooperates with colleagues (1-5): ")
    t2 = get_valid_input("Shares knowledge with team (1-5): ")
    t3 = get_valid_input("Supports team goals (1-5): ")

    teamwork = (t1 + t2 + t3) / 3

    # ATTENDANCE
    a1 = get_valid_input("Punctuality (1-5): ")
    a2 = get_valid_input("Regular attendance (1-5): ")

    attendance = (a1 + a2) / 2

    # INITIATIVE
    i1 = get_valid_input("Takes responsibility for tasks (1-5): ")
    i2 = get_valid_input("Shows problem-solving ability (1-5): ")
    i3 = get_valid_input("Suggests improvements (1-5): ")

    initiative = (i1 + i2 + i3) / 3

    return productivity, quality, teamwork, attendance, initiative


def calculate_base_score(productivity, quality,
                         teamwork, attendance, initiative):

    score = (
        productivity * 0.30 +
        quality * 0.25 +
        teamwork * 0.20 +
        attendance * 0.15 +
        initiative * 0.10
    )

    return score * 20


def apply_expert_rules(percentage, productivity,
                       quality, teamwork,
                       attendance, initiative):

    if attendance == 5:
        percentage += 3

    if teamwork <= 2:
        percentage -= 5

    if productivity >= 4 and quality >= 4:
        percentage += 5

    if initiative <= 2:
        percentage -= 3

    if percentage > 100:
        percentage = 100

    if percentage < 0:
        percentage = 0

    return percentage


def get_rating(percentage):

    if percentage >= 90:
        return "Outstanding"

    elif percentage >= 80:
        return "Excellent"

    elif percentage >= 70:
        return "Very Good"

    elif percentage >= 60:
        return "Good"

    elif percentage >= 50:
        return "Average"

    else:
        return "Needs Improvement"


def give_advice(percentage):

    print("Advice: ", end="")

    if percentage >= 90:
        print("Promotion Recommended")

    elif percentage >= 70:
        print("Eligible for Bonus")

    elif percentage >= 50:
        print("Performance Improvement Suggested")

    else:
        print("Training Required")


# MAIN PROGRAM

print("EMPLOYEE PERFORMANCE EXPERT SYSTEM")
print("----------------------------------")

n = int(input("Enter number of employees: "))

for i in range(1, n + 1):

    print(f"\nEvaluating Employee {i}")

    productivity, quality, teamwork, attendance, initiative = ask_questions()

    percentage = calculate_base_score(
        productivity,
        quality,
        teamwork,
        attendance,
        initiative
    )

    percentage = apply_expert_rules(
        percentage,
        productivity,
        quality,
        teamwork,
        attendance,
        initiative
    )

    rating = get_rating(percentage)

    print(f"\nFinal Score: {percentage}%")
    print("Rating:", rating)

    give_advice(percentage)