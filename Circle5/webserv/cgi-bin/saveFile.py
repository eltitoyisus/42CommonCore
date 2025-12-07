#!/usr/bin/env python3
import os
import sys
from email import policy
from email.parser import BytesParser
from datetime import datetime
from paths import IMG_DIR


def parse_multipart_form_data():
    """Parse multipart form data from stdin"""
    try:
        content_type = os.environ.get('CONTENT_TYPE', '')
        content_length = int(os.environ.get('CONTENT_LENGTH', '0'))
        
        if not content_type.startswith('multipart/form-data'):
            return None
            
        raw_data = sys.stdin.buffer.read(content_length)
        msg_str = f"Content-Type: {content_type}\r\n\r\n"
        msg_str = msg_str.encode() + raw_data
        
        msg = BytesParser(policy=policy.default).parsebytes(msg_str)
        
        form_data = {}
        
        for part in msg.walk():
            if part.get_content_disposition() == 'form-data':
                name = part.get_param('name', header='content-disposition')
                filename = part.get_param('filename', header='content-disposition')
                
                if name:
                    if filename:
                        form_data[name] = {
                            'filename': filename,
                            'content': part.get_content(),
                            'content_type': part.get_content_type()
                        }
                    else:
                        form_data[name] = part.get_content()
        
        return form_data
        
    except Exception as e:
        print(f"<p>Error parsing form data: {e}</p>")
        sys.stderr.write(f"Error parsing form data: {e}\n")
        return {}

form = parse_multipart_form_data()

if form is None:
    print("Status: 400 Bad Request\r")
    print("Content-Type: text/html\r")
    print("\r")
    print("<html><body>")
    print("<h1>400 Bad Request</h1>")
    print("<p>Error: This endpoint only accepts multipart/form-data.</p>")
    print(f"<p>Received Content-Type: {os.environ.get('CONTENT_TYPE', 'not specified')}</p>")
    print("</body></html>")
    sys.exit(0)

if "file" in form and isinstance(form["file"], dict):
    fileitem = form['file']
    filename = fileitem.get('filename')
    print(f"<p>Filename recibido: {filename}</p>")

    if filename:
        safe_filename = os.path.basename(filename)
        filepath = os.path.join(IMG_DIR, safe_filename)
        filepath = os.path.abspath(filepath)

        try:
            content = fileitem['content']
            if isinstance(content, str):
                content = content.encode('latin1')
            with open(filepath, 'wb') as f:
                f.write(content)
            print(f"<p>Archivo '{safe_filename}' subido con éxito.</p>")
        except Exception as e:
            print(f"<p>Error al guardar el archivo: {e}</p>")
    else:
        print("<p>No se ha enviado ningún archivo.</p>")

elif "name" in form or "email" in form or "message" in form:
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    filename = f"contact_{timestamp}.txt"
    filepath = os.path.join(IMG_DIR, filename)
    filepath = os.path.abspath(filepath)
    
    try:
        content = "=== FORMULARIO DE CONTACTO ===\n"
        content += f"Fecha: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n"
        content += "=" * 40 + "\n\n"
        
        if "name" in form:
            content += f"Nombre: {form['name']}\n"
        if "email" in form:
            content += f"Email: {form['email']}\n"
        if "inquiry" in form:
            content += f"Asunto: {form['inquiry']}\n"
        if "message" in form:
            content += f"\nMensaje:\n{form['message']}\n"
        
        content += "\n" + "=" * 40 + "\n"
        
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(content)
        
        print(f"<p>Formulario de contacto guardado como '{filename}'.</p>")
        print(f"<p>Datos procesados correctamente.</p>")
        
    except Exception as e:
        print(f"<p>Error al guardar el formulario: {e}</p>")
        
else:
    print("<p>No se ha enviado ningún archivo o formulario.</p>")

