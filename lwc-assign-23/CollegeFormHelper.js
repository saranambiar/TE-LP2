({
    saveStudentData : function(component) {

        var action = component.get("c.saveStudent");

        action.setParams({

            name : component.get("v.sname"),
            rollNo : component.get("v.rollNo"),
            marks : component.get("v.marks"),
            email : component.get("v.semail")
        });

        action.setCallback(this, function(response) {

            var state = response.getState();

            if(state === "SUCCESS") {

                var result = response.getReturnValue();

                alert(result);

            } else {

                alert("Error Saving Student");
            }
        });

        $A.enqueueAction(action);
    },

    saveFacultyData : function(component) {

        var action = component.get("c.saveFaculty");

        action.setParams({

            name : component.get("v.fname"),
            facultyId : component.get("v.facultyId"),
            salary : component.get("v.salary"),
            email : component.get("v.femail"),
            department : component.get("v.department"),
            joiningDate : component.get("v.joiningDate")
        });

        action.setCallback(this, function(response) {

            var state = response.getState();

            if(state === "SUCCESS") {

                var result = response.getReturnValue();

                alert(result);

            } else {

                alert("Error Saving Faculty");
            }
        });

        $A.enqueueAction(action);
    }
})