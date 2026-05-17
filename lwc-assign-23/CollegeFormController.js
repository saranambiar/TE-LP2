({
    saveStudent : function(component, event, helper) {

        var name = component.get("v.sname");
        var rollNo = component.get("v.rollNo");
        var marks = component.get("v.marks");

        if(name == "") {

            alert("Student name cannot be blank");
            return;
        }

        if(rollNo <= 0) {

            alert("Roll number must be greater than 0");
            return;
        }

        if(marks < 0 || marks > 100) {

            alert("Marks should be between 0 and 100");
            return;
        }

        helper.saveStudentData(component);
    },

    saveFaculty : function(component, event, helper) {

        var name = component.get("v.fname");
        var facultyId = component.get("v.facultyId");
        var salary = component.get("v.salary");
        var department = component.get("v.department");
        var joiningDate = component.get("v.joiningDate");

        if(name.length < 3) {

            alert("Faculty name must contain at least 3 characters");
            return;
        }

        if(facultyId <= 0) {

            alert("Faculty ID must be greater than 0");
            return;
        }

        if(salary < 10000 || salary > 500000) {

            alert("Salary must be between 10000 and 500000");
            return;
        }

        if(department == "") {

            alert("Select department");
            return;
        }

        var today = new Date().toISOString().split('T')[0];

        if(joiningDate > today) {

            alert("Joining date cannot be future date");
            return;
        }

        helper.saveFacultyData(component);
    }
})