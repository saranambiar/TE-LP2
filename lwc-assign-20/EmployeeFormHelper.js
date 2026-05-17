({
    saveData : function(component) {

        var action = component.get("c.saveEmployee");

        action.setParams({

            name : component.get("v.name"),
            empId : component.get("v.empId"),
            salary : component.get("v.salary"),
            email : component.get("v.email"),
            department : component.get("v.department"),
            joiningDate : component.get("v.joiningDate")
        });

        action.setCallback(this, function(response) {

            var state = response.getState();

            if(state === "SUCCESS") {

                alert("Employee Saved Successfully");

            } else {

                var errors = response.getError();

                if(errors && errors[0] && errors[0].message) {

                    alert(errors[0].message);

                } else {

                    alert("Error Saving Employee");
                }
            }
        });

        $A.enqueueAction(action);
    }
})