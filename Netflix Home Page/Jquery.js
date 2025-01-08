// JavaScript Document
$(document).ready(function(){
	$("input").focus(function(){
		$(this).css("background-color","white");
	});
	
	$("input").blur(function(){
		$(this).css("background-color","transparent");
	});
	
//	for (let i = 1; i <= 6; i++){
//		$(`#ques${i}`).click(function() {
//			$(`.a${i}`).slideToggle(100, function() {
//				$(this).css({
//					"padding":"30px 30px",
//					"max-height":"600px"
//				});
//			});
//			$(this).find(".size-6").toggleClass("rotated");
//		});
//	}
	
//	$("#ques1").click(function(){
//		$(".a1").slideToggle(100, function(){
//			$(this).css({
//				"padding":"30px 30px",
//				"max-height":"600px"
//			});
//		});
//	});
	$('#slider').cycle({
	
		next:	"#next",
		prev:	"#prev",
		pager:	"#pager"
	});
//	$('#button').click(function(){
//		window.location.href='login.html';
//	});
	$('#button').click(function(){
//		e.preventDefault();
		window.location.href='login.html';
	});
	$('.inbox').submit(function(e){
		e.preventDefault();
		window.location.href='index.html';
	});
});
