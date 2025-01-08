$(document).ready(function(){
    //add a task of the list
    $('#add').click(function(){
       var task = $('#taskinput').val();
        if(task){
            //apppen list item in the list
            $('#tasklist').append('<li>'+task+'</li>');
            $('#tasklist').val('');
        }
    })

    $('#taskinput').focus(function(){
        $(this).addclass('highlight')

    })
    $('#taskinput').blur(function(){
        $(this).rempoveclass('highlight')
    })

})