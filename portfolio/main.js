$(document).ready(function() {
    // Smooth scrolling for navigation links
    $('.nav-link').on('click', function(event) {
        if (this.hash !== "") {
            event.preventDefault();

            const hash = this.hash;

            $('html, body').animate({
                scrollTop: $(hash).offset().top - 70 // Adjust offset for navbar height
            }, 800, function() {
                window.location.hash = hash;
            });
        }
    });

    // Highlight active section in the navbar
    $(window).on('scroll', function() {
        const scrollPos = $(document).scrollTop();

        $('.nav-link').each(function() {
            const sectionOffset = $($(this).attr('href')).offset().top - 80;

            if (scrollPos >= sectionOffset) {
                $('.nav-link').removeClass('active');
                $(this).addClass('active');
            }
        });
    });

    // Scroll to top button functionality
    const scrollTopBtn = $('<button id="scrollTopBtn" class="btn btn-primary">Top</button>');
    $('body').append(scrollTopBtn);

    scrollTopBtn.hide();

    $(window).on('scroll', function() {
        if ($(this).scrollTop() > 300) {
            scrollTopBtn.fadeIn();
        } else {
            scrollTopBtn.fadeOut();
        }
    });

    scrollTopBtn.on('click', function() {
        $('html, body').animate({
            scrollTop: 0
        }, 800);
    });

    // Form submission alert
    $('form').on('submit', function(event) {
        event.preventDefault(); // Prevent actual form submission
        alert('Thank you for reaching out! I will get back to you soon.');
        $(this).trigger('reset'); // Reset form fields
    });
});
