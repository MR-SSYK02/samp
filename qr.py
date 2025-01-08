import qrcode
from PIL import Image

def generate_qr_code(data):
    # Create a QR Code instance
    qr = qrcode.QRCode(
        version=1,  # controls the size of the QR code
        error_correction=qrcode.constants.ERROR_CORRECT_L,  # error correction
        box_size=10,  # size of each box
        border=4,  # thickness of the border
    )

    # Add data to the QR code
    qr.add_data(data)
    qr.make(fit=True)

    # Create an image from the QR Code
    img = qr.make_image(fill='black', back_color='white')

    return img

def main():
    print("QR Code Generator")
    
    # Get user input
    data = input("Enter the data for the QR Code (e.g., URL or text): ")
    
    # Generate the QR code
    img = generate_qr_code(data)
    
    # Display the image
    img.show()

    # Ask if the user wants to save the image
    save_choice = input("Do you want to save the QR code? (yes/no): ")
    if save_choice.lower() == 'yes':
        filename = input("Enter the filename to save the QR code (e.g., my_qr.png): ")
        img.save(filename)
        print(f"QR code saved as {filename}")
    else:
        print("QR code not saved.")

if __name__ == "__main__":
    main()
