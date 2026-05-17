({
    saveEmployee : function(component, event, helper) {

        var name = component.get("v.name");
        var empId = component.get("v.empId");
        var salary = component.get("v.salary");
        var department = component.get("v.department");
        var joiningDate = component.get("v.joiningDate");

        if(name.length < 3) {
            alert("Name must contain at least 3 characters");
            return;
        }

        if(empId <= 0) {
            alert("Employee ID must be greater than 0");
            return;
        }

        if(salary < 10000 || salary > 500000) {
            alert("Salary must be between 10000 and 500000");
            return;
        }

        if(department == "") {
            alert("Select Department");
            return;
        }

        var today = new Date().toISOString().split('T')[0];

        if(joiningDate > today) {
            alert("Joining date cannot be future date");
            return;
        }

        helper.saveData(component);
    }
})